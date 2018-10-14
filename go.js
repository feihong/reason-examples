const fs = require('fs')
const glob = require('glob')
const childProcess = require('child_process')

if (process.argv.length <= 2) {
  const files = glob
    .sync('**/*.re', {cwd: './src'})
    .map(name => name.substring(0, name.length-3))

  console.log('\nPrograms to run:\n')
  for (let i=0; i < files.length; i++) {
    let f = files[i]
    console.log(`${i+1}. ${f}`)
  }
  console.log()
} else {
  let border = '='.repeat(75)
  let jsFile = 'src/' + process.argv[2] + '.bs.js'

  console.log(`Running ${jsFile}\n${border}\n`)
  let child = childProcess.spawn('node', [jsFile], {stdio: 'inherit'})
}
