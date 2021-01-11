#!/usr/bin/node
const request = require('request');
const myArgs = process.argv.slice(2);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs

};
let dada;
request(options, async (err, res, body) => {
  const json = JSON.parse(body);
  dada = json.characters;
  if (err) {
    throw (err);
  }
  for (const i in dada) {
    await sleep(70);
    const options = {
      url: dada[i]
    };

    request(options, (err, res, body) => {
      const da = JSON.parse(body);
      console.log(da.name);
      if (err) {
        throw (err);
      }
    });
  }
});
function sleep (ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}
