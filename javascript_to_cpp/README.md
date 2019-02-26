
0. Have Node installed ([download node](https://nodejs.org/en/download/))
1. Clone this repo
2. Run `npm install` to install `node-gyp`
    * You can globally install with `npm install -g node-gyp`
    * If its globally installed, you don't need to use npm run (parenthesis commands)
3. Run `npm run configure` (`node-gyp configure`)
4. Run `npm run build` (`node-gyp build`)
    * `npm run rebuild` (`node-gyp rebuild`)
5. Run `npm start` (`node main.js`)
6. You should see the program output 20 for a multiply

## Notes
* `problems.cc` this is where the program logic resides. There's specific sanity check for user input, and the conversions from Javascript Objects to C++ data types
* `package.json` List of user scripts and package dependencies (optional)
* `main.js` The Javascript file which calls the native module
* `binding.gyp` Configuration file for node-gyp, see (Configure)[#Configure]

## Alternatives
If you don't want to install the `bindings` module you can link to the node file  
Replace:  
`const problems = require('bindings')('problems');`  
With the path of the `.node` file:  
`const problems = require('./build/Release/problems.node');`

### Configure
If you want to rename the file/module, you need to specify the target (destination) and source  
`binding.gyp`  
```json
{
  "targets": [
    {
      "target_name": "problems",
      "sources": [ "problems.cc" ]
    }
  ]
}
```

## Resources
* [Official Documentation](https://nodejs.org/api/addons.html])
* [Tutorial](https://medium.com/@tarkus/how-to-call-c-c-code-from-node-js-86a773033892)
