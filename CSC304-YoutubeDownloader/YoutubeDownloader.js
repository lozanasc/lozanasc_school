// import Result from './Result';

const URL = document.getElementById('urlInput');
const AboutInformation = document.querySelector(".groupInformation");
const [ About , Submit, AboutInformationExit ] = document.getElementsByTagName('button');

const Result = (Title , Description , Thumbnail , isVideo) => {
    
    const ResultThumbnail = document.createElement('img');
    ResultThumbnail.src = Thumbnail;

    const ResultTitle = document.createElement('h1');
    ResultTitle.innerHTML = Title;

    const ResultDescription = document.createElement('p');
    ResultDescription.innerHTML = Description;

    const ResultContainer = document.createElement('div');
    ResultContainer.className = 'result';



    // isVideo ? doSomethingHere() : doAnotherStuffHere()

    return ResultContainer;
}

const Download = async(url) => {
    try {
        const Data = await fetch(`https://getvideo.p.rapidapi.com/?url=${url}`, {
            "method": "GET",
            "headers": {
                "x-rapidapi-key": "SECRET 😜",
                "x-rapidapi-host": "getvideo.p.rapidapi.com"
            }
        });
        return Data.json();
    } catch (error) {
        console.log(error);
    }
}

About.addEventListener('click', e => {
    e.preventDefault();
    AboutInformation.classList.toggle('enable');
});

Submit.addEventListener('click', e => {
    e.preventDefault();
    Download(encodeURI(URL.value))
    .then(res => {
        console.log(res);
        
    })
    .catch(err => console.error(err));
});

AboutInformationExit.addEventListener('click', e => {
    e.preventDefault();
    AboutInformation.className = 'groupInformation disable';
});