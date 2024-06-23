// Simple implementation of a Promise.  Does not include Promise chaining
const state = {
    pending: "pending",
    fulfilled: "fulfilled",
    rejected: "rejected",
}

class MyPromise {
    constructor(executor) {
        this.state = state.pending;
        this.value = undefined;
        this.reason = undefined;
        this.onFulfilledCallbacks = [];
        this.onRejectedCallbacks = [];
        const resolve = value => {
            if (this.state === state.pending) {
                this.state = state.fulfilled;
                this.value = value;
                this.onFulfilledCallbacks.forEach(callback => callback(value));
            }
        };
        const reject = reason => {
            if (this.state === state.pending) {
                this.state = state.rejected;
                this.reason = reason;
                this.onRejectedCallbacks.forEach(callback => callback(value));
            }
        }

        try {
            executor(resolve, reject);
        } catch (error) {
            reject(error);
        }
    }

    then(onFulfilled, onRejected) {
        if (this.state === state.pending && onFulfilled) {
            onFulfilled(this.value);
        }
        if (this.state === state.rejected && onRejected) {
            onRejected(this.reason);
        }
        if (this.state === state.pending) {
            if (onFulfilled) {
                this.onFulfilledCallbacks.push(onFulfilled);
            }
            if (onRejected) {
                this.onRejectedCallbacks.push(onRejected);
            }
        }

        return this;
    }

    catch(onRejected) {
        return this.then(null, onRejected);
    }
}

const p = new MyPromise((res, rej) => {
    rej("Fuck you brah");
    setTimeout(() => {
        res("brah");
    }, 2000);
})
    .then(console.log)
    .catch(console.error);














