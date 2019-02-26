const problems = require('bindings')('problems');

(function() {
    console.log(problems.multiply(4, 5));
    console.log(`^^ was that 20? Then it worked!`);
})();
