import "./style/index.scss";

// simple example of using a Promise inside of an async function
async function doSomeAsync(): Promise<void> {
    return new Promise<string>((resolve, reject) => {
        setTimeout(() => {
            resolve("hello brah");
        }, 3000);
    }).then(console.log);
}

async function weAsyncBrah(): Promise<void> {
    await doSomeAsync();
    console.log("yeah buddy hello to you too");
}
// weAsyncBrah();

class MyResponse {
    readonly ok: boolean;
    readonly code: number;
    readonly message: string;
    readonly time: number;
    constructor(ok: boolean, code: number, message: string, time: number) {
        this.ok = ok;
        this.code = code;
        this.message = message;
        this.time = time;
    }
}

function getSimulatedResponse(time: number): MyResponse {
    // errorCode
    const code: number = Math.floor(Math.random() * 5);

    // ok
    let ok: boolean;
    if (code >= 2) {
        ok = true;
    } else {
        ok = false;
    }

    // message
    let message: string;
    if (ok) {
        message = `Success ${code}`;
    } else {
        message = "error message";
    }

    return new MyResponse(ok, code, message, time);
}

function simulateAsyncTask(): Promise<MyResponse> {
    const time: number = Math.floor(Math.random() * 2000) + 500;
    return new Promise((resolve) => {
        const myResponse: MyResponse = getSimulatedResponse(time);
        setTimeout(() => {
            resolve(myResponse);
        }, time);
    });
}

async function fetchData(): Promise<void> {
    try {
        const response: MyResponse = await simulateAsyncTask();
        if (response.ok) {
            console.log(response.message);
        } else {
            throw new Error("http request failed: " + response.message);
        }
    } catch (error) {
        console.error(error);
    }
}

// fetchData();

// promise.race
async function fetchMultipleDataRequests(): Promise<void> {
    const responses: Array<Promise<MyResponse>> = [];
    for (let i = 0; i < 3; i++) {
        const response: Promise<MyResponse> = simulateAsyncTask();
        responses.push(response);
    }
    try {
        const fastestResponse: MyResponse = await Promise.race(responses);
        if (fastestResponse.ok) {
            console.log(`fastest response: ${fastestResponse.message}`);
            console.log(`fastest response in: ${fastestResponse.time}ms`);
        } else {
            throw new Error(
                "Fastest request failed brah: " + fastestResponse.message,
            );
        }
    } catch (err) {
        console.error(err);
    }
}

fetchMultipleDataRequests();
