#!/usr/bin/node
const request = require('request');
const myArgs = process.argv.slice(2);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs

};
let dada;
request(options, function (err, res, body) {
  const json = JSON.parse(body);
  dada = json.characters;
  if (err) {
    throw (err);
  }

  for (let i = 0; i < dada.length; i++) {
    const options = {
      url: dada[i]
    };
    request(options, function (err, res, body) {
      const da = JSON.parse(body);
      console.log(da.name);
      if (err) {
        throw (err);
      }
    });
  }
});
