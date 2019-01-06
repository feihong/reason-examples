include Belt;

module JsPromise = {
  include Js.Promise;

  [@bs.send] external then_: (t('a), 'b) => t('a) = "then";

  [@bs.send] external catch: (t('a), error) => t('a) = "";

  let sleep = ms =>
    make((~resolve, ~reject as _reject) => {
      let value = (); /* must use variable here because of how refmt works */
      Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
    });

  let sleepAndLog = (ms, message) =>
    sleep(ms)->then_(_ => Js.log(message)->resolve);
};
