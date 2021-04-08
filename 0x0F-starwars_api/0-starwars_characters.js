#!/usr/bin/env node
const request = require('request');

const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}`;

request(url, async function (err, res, body) {
  if (err) {
    console.log(err);
    return;
  }

  const allCharacters = JSON.parse(body).characters;

  for (let i = 0; i < allCharacters.length; i++) {
    await new Promise(function (resolve, reject) {
      request(allCharacters[i], function (error, res, bod) {
        if (error) {
          console.log(error);
          reject(error);
        } else {
          console.log(JSON.parse(bod).name);
          resolve();
        }
      });
    });
  }
});
