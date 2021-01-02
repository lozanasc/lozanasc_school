const MainContainer = document.querySelector('.MainContainer');
const ModalButton = document.querySelector('#DownloadBtn');
const ModalResultContainer = document.querySelector('.Result');
const URLInput = document.querySelector('#URLInput');

/**
 * Loading Animation while waiting for Data being Fetched
 */
const SetLoading = () => {
    const LoadingAnimation = document.createElement('img');
    LoadingAnimation.src = '../assets/loading.gif';
    const LoadingContainer = document.createElement('div');
    LoadingContainer.className = 'Loading';
    LoadingContainer.appendChild(LoadingAnimation);

    return LoadingContainer;
}
/**
 * 
 * @param {String} Text
 * @param {Number} Count 
 */
const DescriptionLimiter = (Text, Count) => {
    if(Text.length <= 0)
        return 'No description';
    else
        return Text.slice(0, Count) + (Text.length > Count ? "..." : "");
}
/**
 * 
 * @param {String} FormatName 
 * Video/Audio format name
 * @param {String} FormantDownloadableURL 
 * Downloadable URL
 */
const Downloadable = (FormatName, FormatDownloadableURL) => {
    const DownloadableBtn = document.createElement('button');
    DownloadableBtn.innerHTML = FormatName;
    DownloadableBtn.id = 'Downloadables';
    DownloadableBtn.addEventListener('click', e => window.open(FormatDownloadableURL, '_blank'));
    return DownloadableBtn;
}
// Modal for the Result View
/**
 * 
 * @param {String} Title 
 * title of the Youtube video
 * @param {String} Description 
 * description of the Youtube video
 * @param {String} Thumbnail 
 * thumbnail of the Youtube video
 * @param {Array} DownloadableStream 
 * Array of all Downloadable file formats
 */
const ModalResult = (Title , Description , Thumbnail, DownloadableStream) => {
    
    const ModalCancelButton = document.createElement('button');
    ModalCancelButton.innerHTML = 'Cancel';
    ModalCancelButton.className = 'TextDark';
    ModalCancelButton.addEventListener('click', e => ResultContainer.remove());

    const ResultThumbnail = document.createElement('img');
    ResultThumbnail.src = Thumbnail;

    const ResultTitle = document.createElement('h3');
    ResultTitle.innerHTML = Title;
    ResultTitle.className = 'TextDark';

    const ResultDescription = document.createElement('p');
    ResultDescription.innerHTML = DescriptionLimiter(Description, 250);
    ResultDescription.className = 'TextDark';

    const ResultDownloadableContent = document.createElement('div');
    ResultDownloadableContent.className = 'DownloadableContent';

    DownloadableStream.map(Stream => {
        ResultDownloadableContent.appendChild(Downloadable(Stream.qualityLabel, Stream.url));
    })

    const ResultContainer = document.createElement('div');
    ResultContainer.className = 'Result';
    ResultContainer.append(ModalCancelButton, ResultThumbnail, ResultTitle, ResultDescription, ResultDownloadableContent);

    return ResultContainer;
}

/**
 * 
 * @param {String} url
 * URL of the Youtube video selected
 * ! Free RapidAPI Endpoint for YTDL is Expired
 */
// const Download = async(url) => {
//     try {
//         const Data = await fetch(`https://getvideo.p.rapidapi.com/?url=${encodeURI(url)}`, {
//             "method": "GET",
//             "headers": {
//                 "x-rapidapi-key": API-KEY,
//                 "x-rapidapi-host": "getvideo.p.rapidapi.com"
//             }
//         });
//         return Data.json();
//     } catch (error) {
//         console.log(error);
//     }
// }
const GetVideoDownloadable = async(url) => {
    try{
        const Data = await fetch(`http://localhost:6969/GetInfoDownloadable?url=${url}`,{
            method: 'GET'
        });
        return Data.json();
    }
    catch(error){
        alert(error);
    }
}

ModalButton.addEventListener('click', 
    e => {
        e.preventDefault();
        MainContainer.appendChild(SetLoading());

        GetVideoDownloadable(URLInput.value)
        .then(res => 
        {
            MainContainer.getElementsByClassName('Loading').item(0).remove();
            console.log(res);
            MainContainer.appendChild(ModalResult(res.Title, res.ResultDesc, res.ResultThumbnail, res.ResultDownloadables));
        }
        )
        .catch(err => alert('Something went wrong!', err));
    }
)