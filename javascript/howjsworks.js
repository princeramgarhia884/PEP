const set_api="https://github.com/rajneeshkumar146/pepcoding-Batches/tree/master/2019/LevelUpDecBatch";
const res=fetch(set_api);
console.log(res);
res.then(function(data){
    console.log(data);
});