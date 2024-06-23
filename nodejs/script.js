const axios = require("axios");

axios
    .get("https://google.com")
    .then((response) => {
        console.log(`statusCode: ${response.status}`);
        console.log(response);
    })
    .catch(console.error);
