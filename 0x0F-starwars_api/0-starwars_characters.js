#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

const displayNamesAsync = async char => {
  return new Promise((resolve, reject) => {
    request(char, (error, response, body) => {
      if (response) {
        resolve(JSON.parse(body).name);
      } else if (error) {
        reject(error);
      }
    });
  });
};

request(`https://swapi-api.hbtn.io/api/films/${movieId}/`, async (error, response, body) => {
  if (error) {
    console.log(error);
  } else if (response) {
    const characters = JSON.parse(body).characters;
    for (const char of characters) {
      console.log(await displayNamesAsync(char));
    }
  }
});
