require('isomorphic-fetch')
const fs = require('fs')

fetch("https://picsum.photos/100/100/?random")
  .then(res => res.buffer())
  .then(buffer => {
    console.log('Size in bytes: ' + buffer.length)
    fs.writeFileSync('random.jpg', buffer)
  })
