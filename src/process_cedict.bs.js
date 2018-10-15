// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var Zlib = require("zlib");
var Axios = require("axios");

var url = "https://www.mdbg.net/chinese/export/cedict/cedict_1_0_ts_utf-8_mdbg.txt.gz";

var filename = "cedict.txt.gz";

if (Fs.existsSync(filename)) {
  console.log("Reading cedict.txt.gz");
  var str = Zlib.gunzipSync(Fs.readFileSync(filename)).toString();
  console.log(str);
} else {
  Axios.get(url, {
          responseType: "arraybuffer"
        }).then((function (res) {
          var buffer = res.data;
          Fs.writeFileSync(filename, buffer);
          return Promise.resolve(/* () */0);
        }));
  console.log("Downloaded cedict.txt.gz");
}

exports.url = url;
exports.filename = filename;
/*  Not a pure module */
