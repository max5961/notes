const state = {
    pending: 'pending',
    fulfilled: 'fulfilled',
    rejected: 'rejected'
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
                this.onFulfilledCallbacks.forEach(cb => cb(value));
            }
        };
        const reject = reason => {
            if (this.state === state.pending) {
                this.state = state.rejected;
                this.reason = reason;
                this.onRejectedCallbacks.forEach(cb => cb(value));
            }
        };

        try {
            executor(resolve, reject);
        } catch (error) {
            reject(error);
        }
    }

    then(onFulfilled, onRejected) {
        if (this.state === state.fulfilled && onFulfilled) {
            onFulfilled(this.value);
        }
        if (this.state === state.rejected && onRejected) {
            onRejected(this.reason);
        }
        if (this.state === state.pending) {
            if (onFulfilled) {
                this.onRejectedCallbacks.push(onFulfilled);
            }
            if (onRejected) {
                this.onRejectedCallbacks.push(onRejected);
            }
        }
        
        return new MyPromise()
    }
}
