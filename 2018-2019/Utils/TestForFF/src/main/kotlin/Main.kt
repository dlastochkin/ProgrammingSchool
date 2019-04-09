import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.net.Socket

fun main(args: Array<String>) {
    println("Hello Valeria!\n")

    var goNext = true
    val reader = BufferedReader(InputStreamReader(System.`in`))

    while (goNext) {
        try {
            print("Address: ")
            val addr = reader.readLine()
            print("Port: ")
            val port = reader.readLine().toInt()

            goNext = Sender(addr, port).run()
        } catch (ex: Throwable) {
            println("Я поймал исключение, вот оно: $ex\n")
        }
    }
}

class Sender(address: String, port: Int) {

    private val socket: Socket = Socket(address, port)

    fun run(): Boolean {
        var goNext = false
        val reader = BufferedReader(InputStreamReader(System.`in`))

        BufferedReader(InputStreamReader(socket.getInputStream())).use { ins ->
            BufferedWriter(OutputStreamWriter(socket.getOutputStream())).use { outs ->
                var isNext = true
                while (isNext) {
                    print("Напиши строчку для отправки (или /exit, /next, /read):")
                    reader.readLine().also {
                        when (it) {
                            "/exit" -> isNext = false
                            "/next" -> {
                                isNext = false
                                goNext = true
                            }
                            "/read" -> println(ins.readLine())
                            else -> {
                                outs.write(it)
                                outs.flush()
                            }
                        }
                    }
                }
            }
        }

        socket.close()

        return goNext
    }
}