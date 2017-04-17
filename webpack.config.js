const path = require('path');

module.exports = {
    entry: {
        simple: './lib/js/src/simple/simpleRoot.js',
        logo: './lib/js/src/logo/logoRoot.js',
        todomvc: './lib/js/src/todomvc/app.js',
        interop: './src/interop/interopRoot.js',
        'tic-tac-toe': './lib/js/src/tic-tac-toe/index.js',
    },
    output: {
        path: path.join(__dirname, 'bundledOutputs'),
        filename: '[name].js',
    },
};
