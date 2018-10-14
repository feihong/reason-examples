open Express;

let app = express();

let randomIntRange = (min, max) => Random.int(max - min + 1) + min;

let getCharFromRange = (min, max) => {
  let ordinal = randomIntRange(min, max);
  let text = Js.String.fromCodePoint(ordinal);
  (text, ordinal);
};

let getHtml = hanzi => {j|
<h1>你好世界！</h1>

<p style='font-size: 5rem; margin-top: 0;'>$hanzi</p>
|j};

App.get(app, ~path="/") @@
Middleware.from((_next, _req) => {
  let (hanzi, ordinal) = getCharFromRange(0x4e00, 0x9fff);
  Js.log((hanzi, ordinal));
  getHtml(hanzi)->Response.sendString;
});

let port = 8000;
let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ {j|Listening at http://127.0.0.1:$port|j}
  };

let server = App.listen(app, ~port, ~onListen, ());
