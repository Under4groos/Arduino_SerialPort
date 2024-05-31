using System.IO.Ports;

SerialPort port = new SerialPort("COM4",
    9600, Parity.None, 8, StopBits.One);
port.DataReceived += Port_DataReceived;
port.Open();

void Port_DataReceived(object sender, SerialDataReceivedEventArgs e)
{

    int count = port.BytesToRead;
    byte[] ByteArray = new byte[count];
    port.Read(ByteArray, 0, count);
    Console.WriteLine(System.Text.Encoding.Default.GetString(ByteArray));
}
while (true) ;