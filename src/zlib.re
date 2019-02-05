open Interop;

let str =
  Array.make(100, {js|你好世界！|js})
  ->Array.mapWithIndex((i, v) => {
      let i = i + 1;
      {j|$i. $v\n|j};
    })
  |> Js.Array.joinWith("");

let buffer = Node.Buffer.fromString(str);
Js.log2("Original size:", buffer->Buffer.length->string_of_int);

let buffer2 = Zlib.gzipSync(buffer);
Js.log2("Compressed size:", buffer2->Buffer.length->string_of_int);

Fs.writeBufferToFileSync("output.gz", buffer2);
Js.log("Wrote to file output.gz");
/* Run `cat output.gz | gunzip` to see contents */
