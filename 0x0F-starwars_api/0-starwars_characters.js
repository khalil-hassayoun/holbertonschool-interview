#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
const data = [];
request(url, function (err, res, body) {
  if (err) console.log(err);
  else if (res.statusCode === 200) {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      data.push({ url: characters[i], name: '' });
      request(characters[i], function (error, resp, body2) {
        if (error) console.log(error);
        data[i].name = JSON.parse(body2).name;
        if (checkdata(data)) {
          for (let j = 0; j < data.length; j++) {
            console.log(data[j].name);
          }
        }
        // console.log(JSON.parse(body2).name);
      });
    }
  }
});
function checkdata (data) {
  for (let i = 0; i < data.length; i++) {
    if (data[i].name === '') { return false; }
  }
  return true;
}
