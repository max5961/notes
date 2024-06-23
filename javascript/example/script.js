function createTask() {
    function getRandomTimeOut() {
        return Math.floor(Math.random() * 500);
    }

    return new Promise((res, rej) => {
        const timeout = getRandomTimeOut();

        const resTimeout = setTimeout(() => {
            clearTimeout(rejTimeout);
            res(timeout);
        }, timeout);

        const rejTimeout = setTimeout(() => {
            clearTimeout(resTimeout);
            rej(new Error(timeout));
        }, 400);
    })
}

const tasks = [
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
    createTask,
];

function createQueue(tasks, maxConcurrent = 4) {
    return new Promise((res) => {
        const results = new Array(tasks.length).fill(0);
        currentTasks = 0;
        currentIndex = 0;

        function handleSettle() {
            --currentTasks;
        }

        function handleResolve(index) {
            return (result) => {
                results[index] = `Success: ${result}`;
                addTask();
            }
        }

        function handleReject(index) {
            return (reason) => {
                results[index] = `Failure: ${reason.message}`;
                addTask();
            }
        }

        function addTask() {
            if (currentIndex < tasks.length && currentTasks < maxConcurrent) {
                tasks[currentIndex]()
                    .finally(handleSettle)
                    .then(handleResolve(currentIndex))
                    .catch(handleReject(currentIndex));
                ++currentIndex;
                ++currentTasks;
                addTask();
            } else if (currentTasks === 0 && currentIndex === tasks.length) {
                res(results);
            }
        }

        addTask();
    })
}

async function logResults() {
    console.log(await createQueue(tasks, 4));
}

logResults();






