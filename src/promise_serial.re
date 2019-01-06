open Prelude;
module P = JsPromise;

Js.log("I'm sleepy...");
P.sleep(1000)
->P.then_(_ => {
    Js.log("woke up after 1000");
    P.sleep(1200);
  })
->P.then_(_ => Js.log("woke up after 1200")->P.resolve);
