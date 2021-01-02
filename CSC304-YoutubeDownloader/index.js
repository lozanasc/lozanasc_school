const express = require('express');
const app = express();
const port = process.env.PORT || 6969;
const path = require('path');
const ytdl = require('ytdl-core');
const fetch = require('node-fetch');
const cors = require('cors');

require('dotenv').config();
app.use(cors());

app.use('/', express.static(path.join(__dirname, 'public')));
app.use('/assets', express.static(path.join(__dirname, 'assets')));
app.use('/js', express.static(path.join(__dirname, 'js')));

app.get('/Download', (request, response) => {
    const {url} = request.query;
    
    response.header('Content-Disposition','attachment; filename="video.mp4"');

    ytdl(url, {
        format: 'mp4'
    }).pipe(response);
});

app.get('/GetInfoDownloadable', (request, response) => {
    const {url} = request.query;

    ytdl.getInfo(url)
    .then(
        res => {
            response.json(res)
        }
    ).catch(error => console.log(error));
})

app.listen(port, () => {
    console.log(`Development server is listening at http://localhost:${[port]}`);
})  