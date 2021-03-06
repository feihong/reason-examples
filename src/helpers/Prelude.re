module Utils = {
  /* log list of lists */
  let logList = lst => lst->List.toArray->Array.map(List.toArray)->Js.log;
};

module JsPromise = {
  include Js.Promise;

  [@bs.send] external then_: (t('a), 'a => t('b)) => t('b) = "then";

  [@bs.send] external catch: (t('a), error => t('a)) => t('a) = "";

  let sleep = ms =>
    make((~resolve, ~reject as _reject) => {
      let value = (); /* must use variable here because of how refmt works */
      Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
    });

  let sleepAndLog = (ms, message) =>
    sleep(ms)->then_(_ => Js.log(message)->resolve);

  /* Modeled after Bluebird's Promise.reduce */
  let rec reduce = (lst, acc, reducer) =>
    switch (lst) {
    | [] => resolve(acc)
    | [head, ...rest] =>
      reducer(acc, head)->then_(newAcc => reduce(rest, newAcc, reducer))
    };
};
