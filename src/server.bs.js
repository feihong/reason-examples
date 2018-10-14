// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Random = require("bs-platform/lib/js/random.js");
var Express = require("bs-express/src/Express.js");
var Process = require("process");

var app = Express.express(/* () */0);

function randomIntRange(min, max) {
  return Random.$$int((max - min | 0) + 1 | 0) + min | 0;
}

function getCharFromRange(min, max) {
  var ordinal = randomIntRange(min, max);
  var text = String.fromCodePoint(ordinal);
  return /* tuple */[
          text,
          ordinal
        ];
}

function getHtml(hanzi) {
  return "\n<h1>你好世界！</h1>\n\n<p style=\'font-size: 5rem; margin-top: 0;\'>" + (String(hanzi) + "</p>\n");
}

Express.App[/* get */4](app, "/", Express.Middleware[/* from */5]((function (_, _$1) {
            var match = getCharFromRange(19968, 40959);
            var hanzi = match[0];
            console.log(/* tuple */[
                  hanzi,
                  match[1]
                ]);
            var partial_arg = getHtml(hanzi);
            var partial_arg$1 = Express.Response[/* sendString */2];
            return (function (param) {
                return partial_arg$1(partial_arg, param);
              });
          })));

function onListen(e) {
  var exit = 0;
  var val;
  try {
    val = e;
    exit = 1;
  }
  catch (raw_exn){
    var exn = Js_exn.internalToOCamlException(raw_exn);
    if (exn[0] === Js_exn.$$Error) {
      console.log(exn[1]);
      Process.exit(1);
      return /* () */0;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    console.log("Listening at http://127.0.0.1:" + (String(8000) + ""));
    return /* () */0;
  }
  
}

var server = Express.App[/* listen */19](app, 8000, onListen, /* () */0);

var port = 8000;

exports.app = app;
exports.randomIntRange = randomIntRange;
exports.getCharFromRange = getCharFromRange;
exports.getHtml = getHtml;
exports.port = port;
exports.onListen = onListen;
exports.server = server;
/* app Not a pure module */
