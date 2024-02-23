const net = require('net');
const fs = require('fs');

const SERVER_PORT = 12345;

const server = net.createServer((socket) => {
  socket.on('data', (data) => {
    // Aquí puedes manejar los datos recibidos del cliente si es necesario
  });

  socket.on('end', () => {
    console.log('Cliente desconectado');
  });

  const fileStream = fs.createReadStream('Archivos_prueba\\hola1.txt');

  fileStream.pipe(socket);

  fileStream.on('end', () => {
    console.log('Transferencia de archivo completa');
    socket.end(); // Cierra la conexión con el cliente
  });
});

server.listen(SERVER_PORT, () => {
  console.log('Servidor escuchando en el puerto ${SERVER_PORT}');
})