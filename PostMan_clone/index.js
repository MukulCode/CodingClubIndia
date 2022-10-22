console.log('This is my project 6 from JavaScript Course');

// Utility Functions. 

// 1. Utility function to get DOM element from the string. 
function getElementFromString(str) {
    let div = document.createElement('div');
    div.innerHTML = str;
    return div.firstElementChild;
}
// 2. 



// Count of number of added params. 
let addedParamCount = 0;

// Hide the parametersBox initially. 
let parametersBox = document.getElementById('parametersBox');
parametersBox.style.display = 'none';

// If the user clicks on params box, hide the json box. 
let paramsRadio = document.getElementById('paramsRadio');
paramsRadio.addEventListener('click', () => {
    document.getElementById('requestJsonBox').style.display = 'none';
    document.getElementById('parametersBox').style.display = 'block';
})

// if the user clicks on json box, hide the param box. 
let jsonRadio = document.getElementById('jsonRadio');
jsonRadio.addEventListener('click', () => {
    document.getElementById('parametersBox').style.display = 'none';
    document.getElementById('requestJsonBox').style.display = 'block';
})

// If the user clicks on + button, add more parameters.Inside it, - button logic is also written. 
let addParam = document.getElementById('addParam');
addParam.addEventListener('click', () => {
    let params = document.getElementById('params');
    let html = `   <div class="input-group mb-3">
                         <label for="inputJson" class="col-sm-2 col-form-label">Parameter ${addedParamCount + 2}</label>
                        <input type="text" id="parameterKey${addedParamCount + 2}" class="form-control mx-2" placeholder="Enter Parameter ${addedParamCount + 2} Key" aria-label="parameterKey${addedParamCount + 2}">
                        <input type="text" id="parameterValue${addedParamCount + 2}" class="form-control mx-2" placeholder="Enter Parameter ${addedParamCount + 2} value" aria-label="parameterValue${addedParamCount + 2}">
                        <button class="btn btn-primary deleteParam"> - </button>
                    </div>`;
    addedParamCount++;
    // params.innerHTML += html;// this can also be used to add 

    // this is another way to add the element in the dom. 
    let paramElement = getElementFromString(html);
    params.appendChild(paramElement);
    // console.log(paramElement);

    // Add an event listener to remove the parameter on clicking - button. 
    let deleteParam = document.getElementsByClassName('deleteParam');
    for (item of deleteParam) {
        item.addEventListener('click', (e) => {
            e.target.parentElement.remove();
        })
    }


})

// If the user clicks on submit button. 
let submit = document.getElementById('submit');
submit.addEventListener('click', () => {
    // Show please wait in the respose box to request patience from the use3r. 
    // document.getElementById('responseJsonText').value = "Please Wait.....Fetching response";
    document.getElementById('responsePrism').innerHTML = "Please Wait.....Fetching response";

    // Fetch all the values userf has entered. 
    // This shows how to select radio boxes. 
    let url = document.getElementById('url').value;
    let requestType = document.querySelector("input[name='requestType']:checked").value;
    let contentType = document.querySelector("input[name='contentType']:checked").value;

    // If the user has used params option instead of json, collect all the parameters in an object. 
    let data;
    if (contentType == 'params') {
        data = {};
        for (let i = 0; i < addedParamCount + 1; i++) {
            if (document.getElementById(`parameterKey${i + 1}`) != undefined) {
                let key = document.getElementById(`parameterKey${i + 1}`).value;
                let value = document.getElementById(`parameterValue${i + 1}`).value;
                data[key] = value;
            }
        }
        data = JSON.stringify(data);
    }
    else {
        data = document.getElementById('requestJsonText').value;
    }

    // Log all the values in the console for debugging. 
    // console.log("URL is ", url);
    // console.log("requestType is ", requestType);
    // console.log("contentType is ", contentType);
    // console.log("data is ", data);

    // If the request type is post invoke fetch api to create a post request. 
    if (requestType == 'GET') {
        fetch(url, {
            method: 'GET',
        })
            .then(response => response.text())
            .then((text) => {
                // document.getElementById('responseJsonText').value = text;
                document.getElementById('responsePrism').innerHTML = text;
                Prism.highlightAll();
            })
    }
    else {
        fetch(url, {
            method: 'POST',
            body: data,
            headers: {
                "Content-type": "application/json; charset=UTF-8"
            }
        })
            .then(response => response.text())
            .then((text) => {
                // document.getElementById('responseJsonText').value = text;
                document.getElementById('responsePrism').innerHTML = text;
                Prism.highlightAll();
            });
    }
})

