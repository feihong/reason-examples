/**
 * Print out a compressed text file's contents, line by line.
 */
const { pipeline, Duplex, Transform } = require('stream')
const fs = require('fs')
const readline = require('readline')
const zlib = require('zlib')

let readStream = fs.createReadStream('output.gz')
let gunzip = zlib.createGunzip()
pipeline(readStream, gunzip)

let interface = readline.createInterface({input: gunzip})
interface.on('line', line => {
  console.log(line)
})
interface.on('close', () => {
  console.log('No more lines');
})
