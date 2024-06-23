class RequestQueue {
    constructor(maxConcurrent = 3) {
        this.maxConcurrent = maxConcurrent;
        this.running = 0;
        this.queue = [];
    }

    enqueue(promiseFactory) {
        return new Promise((resolve, reject) => {
            const task = async () => {
                try {
                    this.running++;
                    const result = await promiseFactory();
                    resolve(result);
                } catch (error) {
                    reject(error);
                } finally {
                    this.running--;
                    this._checkQueue
                }
            }
        })
    }
}
