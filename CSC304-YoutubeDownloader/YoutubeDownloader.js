const URL = document.getElementById('UrlInput');
const [ About , Submit ] = document.getElementsByTagName('button');
var isAboutEnabled = false;

About.addEventListener('click', e => {
    e.preventDefault();
});

Submit.addEventListener('click', e => {
    e.preventDefault();
    console.log('It works too');
});