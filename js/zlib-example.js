const zlib = require('zlib')
const fs = require('fs')

let str =
  (new Array(100))
  .fill('你好世界！')
  .map((v, i) => `${i+1}. ${v}\n`)
  .join('')

let buffer = Buffer.from(str)
console.log('Original size:', buffer.length)

let buffer2 = zlib.gzipSync(buffer)
console.log('Compressed size: ' + buffer2.length)
fs.writeFileSync('output.gz', buffer2)
