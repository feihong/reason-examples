const axios = require('axios')
const fs = require('fs')

axios.get("https://picsum.photos/100/100/?random", {responseType: 'arraybuffer'})
  .then(res => {
    let buffer = res.data
    console.log('Size in bytes: ' + buffer.length)
    fs.writeFileSync('random.jpg', buffer)
  })
