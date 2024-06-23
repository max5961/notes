// Create a custom class called MyPromise which is a simplified version of the JavaScript built in Promise class

// Create a function delay(n, value) that returns a Promise that resolves to 'value' after 'n' seconds
function delay(n, value) {
    return new Promise((resolve, reject) => {
        setTimeout(() => resolve(value), n);
    })
}
// delay(2000, 'hello world').then(console.log);


// Create a function sum(a, b) that resolves to the sum of two numbers.  If any of the inputs are
// not numbers, the promise should reject
function sum(a, b) {
    return new Promise((resolve, reject) => {
        if (typeof a !== 'number' || typeof b !== 'number') {
            reject(new Error("Args must be numbers"));
        } else {
            resolve(a + b);
        }
    });
}
// sum(5,'4').then(console.log);

// Create a function chainPromises that takes a number and resolves to that number * 2.
// Chain together Promises so that an input of 5 returns 80 after to of the Promises are chained
// Console.log the result
function chainPromises(n) {
    return new Promise((resolve, reject) => {
        setTimeout(() => resolve(n * 2), 2000);
    });
}
// chainPromises(5)
//     .then(n => chainPromises(n))
//     .then(n => chainPromises(n))
//     .then(n => chainPromises(n))
//     .then(console.log);


// Create a function processData that takes an array of numbers and a string representing an operation
// The operation param will be either add or multiply.  The function will return a Promise that resolves to the
// sum or product of the numbers in the array and their corresponding operation
// the .then and .catch method will be chained to the function to handle the success or failure of the Promise
function processData(data, operation) {
    return new Promise((resolve, reject) => {
        if (data.find(num => typeof num !== 'number')) {
            reject(new Error("Arg1 should be an array containing only variables of type: number"))
        } else if (operation === 'add') {
            setTimeout(() => resolve(data.reduce((acc, curr) => acc + curr), 0), 3000);
        } else if (operation === 'multiply') {
            setTimeout(() => resolve(data.reduce((acc, curr) => acc * curr), 1), 3000);
        } else {
            reject(new Error('Invalid operation'));
        }
    })
}
// processData([5,'dsf',2,6], 'multiply').then(console.log).catch(console.log);

// EXPLAIN THE EVENT LOOP
// Execute any function calls on the call stack
// If the call stack is empty, the event loop looks into the task queue (callback queue).
// If there are any waiting callbacks (i.e from a setTimeout or another operation), the event loop pops them off
// and pushes them to the call stack for execution
// EXPLAIN WHAT HAPPENS WHEN THE ENGINE ENCOUNTERS AN ASYNC FUNCTION
// The engine hands off the task to the corresponding Web API.
// Once the task is completed, it is pushed to the callback queue
// When an event listener is assigned to an HTML object, it triggers the browsers Web API to listen for that event
// When the event occurs, the asssociated event callback is enqueued to the task/callback queue.
