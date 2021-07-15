## Concepts：

At its core,webpack is a static module bundler for `JS` applications. 

When webpack precesses your application, it internally builds `dependency graph` which maps every module your projects needs and generates one or more bundles.

By default its value is `./src/index.js`



### Entry

An entry point indicates which module webpack should use to begin building out its internal dependency graph.



### Output

The `output` property tells webpack where to emit the bundles it creates and how to name these files.It defaults to `./dist/main.js`



### loader

out of the box, webpack only unstandstands JS and JSON files.

`Loaders` allow webpack to process other types of files and convert them into valid modules that can be consume by your application and added to the dependency graph.



### plugin

While loaders are used to transform certain types of modules , plugins can be leveraged to perform a wider range of tasks like bundle optimization, assets management and injection of environment variables.

























