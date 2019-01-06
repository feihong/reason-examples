open Prelude;
module P = JsPromise;

Js.log("I'm sleepy...");
P.sleepAndLog(1000, "woke up after 1000")
->P.then_(_ => P.sleepAndLog(1200, "woke up after 1200"))
->P.then_(_ => P.sleepAndLog(1500, "woke up after 1500"))
->P.then_(_ => Js.log("done!")->P.resolve);
