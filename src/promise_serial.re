open Prelude;
module P = JsPromise;

let simple = () => {
  Js.log("I'm sleepy...");
  P.sleepAndLog(1000, "woke up after 1000")
  ->P.then_(_ => P.sleepAndLog(1200, "woke up after 1200"))
  ->P.then_(_ => P.sleepAndLog(1500, "woke up after 1500"))
  ->P.then_(_ => Js.log("simple is done!")->P.resolve);
};

let reduce = () =>
  [100, 1000, 1200, 1500, 600]
  ->P.reduce(0, (acc, n) =>
      P.sleepAndLog(n, {j|woke up after $n|j})
      ->P.then_(_ => P.resolve(acc + n))
    )
  ->P.then_(total =>
      Js.log({j|Slept a total of $total milliseconds.|j})->P.resolve
    );

let downloads = () => {
  let fakeDownload = url => P.sleepAndLog(888, {j|Downloaded $url|j});

  ["foo.com", "bar.net", "baz.us", "cooldog.us"]
  ->P.reduce((), (_acc, url) => fakeDownload(url))
  ->P.then_(_ => Js.log("Downloads finished.")->P.resolve);
};

/* simple(); */
/* reduce(); */
downloads();
