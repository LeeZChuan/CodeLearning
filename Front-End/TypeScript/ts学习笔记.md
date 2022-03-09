# �ӿ�
## ֻ������
һЩ��������ֻ���ڶ���ոմ�����ʱ���޸���ֵ�� �������������ǰ�� readonly��ָ��ֻ�����ԣ�
```ts
let a: number[] = [1, 2, 3, 4];
let ro: ReadonlyArray<number> = a;
ro[0] = 12; // error!
ro.push(5); // error!
ro.length = 100; // error!
a = ro; // error!
```

�����������һ�У����Կ������������ReadonlyArray��ֵ��һ����ͨ����Ҳ�ǲ����Եġ� ��������������Ͷ�����д��
```ts
a = ro as number[];
```

# ���Ͷ���

��ʱ������������������������TypeScript���˽�ĳ��ֵ����ϸ��Ϣ�� ͨ����ᷢ�����������֪��һ��ʵ����б����������͸�ȷ�е����͡�

ͨ��*���Ͷ���*���ַ�ʽ���Ը��߱��������������ң���֪���Լ��ڸ�ʲô���� ���Ͷ��Ժñ����������������ת�������ǲ�������������ݼ��ͽ⹹�� ��û������ʱ��Ӱ�죬ֻ���ڱ���׶������á� TypeScript������㣬����Ա���Ѿ������˱���ļ�顣

* ���Ͷ�����������ʽ�� ��һ�ǡ������š��﷨��

```ts
let someValue: any = "this is a string"; 

let strLength: number = (<string>someValue).length;
```

* ��һ��Ϊ`as`�﷨��

```ts
let someValue: any = "this is a string";

let strLength: number = (someValue as string).length;
```

������ʽ�ǵȼ۵ġ� ����ʹ���ĸ�������������ƾ����ϲ�ã�Ȼ����������TypeScript��ʹ��JSXʱ��ֻ�� `as`�﷨�����Ǳ�����ġ�



## ȫ�º�������

Ϊ��ʹ�ýӿڱ�ʾ�������ͣ�������Ҫ���ӿڶ���һ������ǩ���� 
��������һ��ֻ�в����б�ͷ���ֵ���͵ĺ������塣�����б����ÿ����������Ҫ���ֺ����͡�

```ts
interface SearchFunc {
  (source: string, subString: string): boolean;
}

������������ǿ�����ʹ�������ӿ�һ��ʹ������������͵Ľӿڡ� 
����չʾ����δ���һ���������͵ı���������һ��ͬ���͵ĺ�����ֵ�����������
let mySearch: SearchFunc;
mySearch = function(source: string, subString: string) {
  let result = source.search(subString);
  return result > -1;
}
```

## ������������
��ʹ�ýӿ������������Ͳ�࣬����Ҳ����������Щ�ܹ���ͨ�������õ��������ͣ�
����a[10]��ageMap["daniel"]�� ���������;���һ�� ����ǩ�����������˶������������ͣ�
������Ӧ����������ֵ���͡� �����ǿ�һ�����ӣ�

```ts
interface StringArray {
  [index: number]: string;
}

let myArray: StringArray;
myArray = ["Bob", "Fred"];

let myStr: string = myArray[0];

//TypeScript֧����������ǩ�����ַ���������
```

## ��-����
### ʵ�ֽӿ�
### �̳нӿ�
����һ�����ӿ�Ҳ�����໥�̳С� ���������ܹ���һ���ӿ��︴�Ƴ�Ա����һ���ӿ�����Ը����ؽ��ӿڷָ�����õ�ģ���
```ts
interface Shape {
    color: string;
}

interface Square extends Shape {
    sideLength: number;
}

let square = <Square>{};
square.color = "blue";
square.sideLength = 10;
```

�ӿڼ̳���
���ӿڼ̳���һ��������ʱ������̳���ĳ�Ա����������ʵ�֡� �ͺ���ӿ��������������д��ڵĳ�Ա������û���ṩ����ʵ��һ���� �ӿ�ͬ����̳е����private��protected��Ա�� ����ζ�ŵ��㴴����һ���ӿڼ̳���һ��ӵ��˽�л��ܱ����ĳ�Ա����ʱ������ӿ�����ֻ�ܱ���������������ʵ�֣�implement����

������һ���Ӵ�ļ̳нṹʱ������ã���Ҫָ��������Ĵ���ֻ������ӵ���ض�����ʱ�����á� ���������˼̳��������������û���κι�ϵ��

```ts
class Control {
    private state: any;
}

interface SelectableControl extends Control {
    select(): void;
}

class Button extends Control implements SelectableControl {
    select() { }
}

class TextBox extends Control {
    select() { }
}

// ���󣺡�Image������ȱ�١�state�����ԡ�
class Image implements SelectableControl {
    select() { }
}

class Location {

}
```

## ������˽�����ܱ��������η�
###### Ĭ��Ϊ public
###### private:����Ա����ǳ� privateʱ�����Ͳ�����������������ⲿ���ʡ�
###### protected:protected���η��� private���η�����Ϊ�����ƣ�����һ�㲻ͬ�� protected��Ա������������Ȼ���Է��ʡ�



```ts
class Person {
    protected name: string;
    constructor(name: string) { this.name = name; }
}

class Employee extends Person {
    private department: string;

    constructor(name: string, department: string) {
        super(name)
        this.department = department;
    }

    public getElevatorPitch() {
        return `Hello, my name is ${this.name} and I work in ${this.department}.`;
    }
}

let howard = new Employee("Howard", "Sales");
console.log(howard.getElevatorPitch());
console.log(howard.name); // ����
```
ע�⣬���ǲ����� Person����ʹ�� name������������Ȼ����ͨ�� Employee���ʵ���������ʣ���Ϊ Employee���� Person���������ġ�

### readonly���η�
�����ʹ�� readonly�ؼ��ֽ���������Ϊֻ���ġ� ֻ�����Ա���������ʱ���캯���ﱻ��ʼ����

## ��ȡ��
TypeScript֧��ͨ��getters/setters����ȡ�Զ����Ա�ķ��ʡ� ���ܰ�������Ч�Ŀ��ƶԶ����Ա�ķ��ʡ�

����������ΰ�һ���򵥵����д��ʹ�� get�� set�� ���ȣ����Ǵ�һ��û��ʹ�ô�ȡ�������ӿ�ʼ��
```ts
class Employee {
    fullName: string;
}

let employee = new Employee();
employee.fullName = "Bob Smith";
if (employee.fullName) {
    console.log(employee.fullName);
}
```
���ǿ������������ fullName�����Ƿǳ�����ģ�������Ҳ���ܻ�����鷳��

��������汾������ȼ���û������Ƿ���ȷ��Ȼ�����������޸�Ա����Ϣ�� ���ǰѶ� fullName��ֱ�ӷ��ʸĳ��˿��Լ������� set������ ����Ҳ����һ�� get�������������������Ȼ���Թ�����
```ts
let passcode = "secret passcode";

class Employee {
    private _fullName: string;

    get fullName(): string {
        return this._fullName;
    }

    set fullName(newName: string) {
        if (passcode && passcode == "secret passcode") {
            this._fullName = newName;
        }
        else {
            console.log("Error: Unauthorized update of employee!");
        }
    }
}

let employee = new Employee();
employee.fullName = "Bob Smith";
if (employee.fullName) {
    alert(employee.fullName);
}
```

## this�ͼ�ͷ����


## ����
������Ҫһ�ַ���ʹ����ֵ�������봫���������������ͬ�ġ� �������ʹ���� ���ͱ���������һ������ı�����ֻ���ڱ�ʾ���Ͷ�����ֵ��
```ts
function identity<T>(arg: T): T {
    return arg;
}
```
ʹ�÷��ͱ���
ʹ�÷��ʹ�����identity�����ķ��ͺ���ʱ��������Ҫ�����ں����������ȷ��ʹ�����ͨ�õ����͡�
���仰˵����������Щ����������������������͡�
### ���Ͷ�����

## ö��

ʹ��ö�����ǿ��Զ���һЩ�����ֵĳ����� ʹ��ö�ٿ��������ر����ͼ�򴴽�һ��������������� TypeScript֧�����ֵĺͻ����ַ�����ö�١�

## �߼�������Ҫ��ѧϰһ��

##### �������ͣ�Union Types��

�������ͱ�ʾһ��ֵ�����Ǽ�������֮һ�� ���������ߣ� `|`���ָ�ÿ�����ͣ����� `number | string | boolean`��ʾһ��ֵ������ `number`�� `string`���� `boolean`��

���һ��ֵ���������ͣ�����ֻ�ܷ��ʴ��������͵����������ﹲ�еĳ�Ա��

```ts
interface Bird {
    fly();
    layEggs();
}

interface Fish {
    swim();
    layEggs();
}

function getSmallPet(): Fish | Bird {
    // ...
}

let pet = getSmallPet();
pet.layEggs(); // okay
pet.swim();    // errors
```

### Symbols

Symbols�ǲ��ɸı���Ψһ�ġ�

```ts
let sym2 = Symbol("key");
let sym3 = Symbol("key");

sym2 === sym3; // false, symbols��Ψһ��
```
���ַ���һ����symbolsҲ���Ա������������Եļ���
```ts
let sym = Symbol();

let obj = {
    [sym]: "value"
};

console.log(obj[sym]); // "value"
```
SymbolsҲ����������������������������������������Ժ����Ա��
```ts
const getClassNameSymbol = Symbol();

class C {
    [getClassNameSymbol](){
       return "C";
    }
}

let c = new C();
let className = c[getClassNameSymbol](); // "C"
```
## ��������������
### �ɵ�����
#### for..of ���
for..of������ɵ����Ķ��󣬵��ö����ϵ�Symbol.iterator������ ��������������ʹ�� for..of�ļ����ӣ�
```ts
let someArray = [1, "string", false];

for (let entry of someArray) {
    console.log(entry); // 1, "string", false
}
```
#### for..of vs. for..in ���
for..of��for..in���ɵ���һ���б��������ڵ�����ֵȴ��ͬ��for..in�������Ƕ���� �� ���б���for..of���������ļ���Ӧ��ֵ��

���������չʾ������֮�������
```ts
let list = [4, 5, 6];

for (let i in list) {
    console.log(i); // "0", "1", "2",
}

for (let i of list) {
    console.log(i); // "4", "5", "6"
}
```
��һ��������for..in���Բ����κζ������ṩ�˲鿴�������Ե�һ�ַ����� ���� for..of��ע�ڵ��������ֵ�����ö���Map��Set�Ѿ�ʵ����Symbol.iterator�����������ǿ��Է������Ǳ����ֵ��

## ģ��-��Ҫ
### ����
#### ��������
�κ�����������������������࣬���ͱ�����ӿڣ����ܹ�ͨ�����export�ؼ�����������
```ts
export interface StringValidator {
    isAcceptable(s: string): boolean;
}
//����
export const numberRegexp = /^[0-9]+$/;

export class ZipCodeValidator implements StringValidator {
    isAcceptable(s: string) {
        return s.length === 5 && numberRegexp.test(s);
    }
}
```
�������ܱ�������Ϊ���ǿ�����Ҫ�Ե����Ĳ�����������������������ӿ���������д��
```ts
class ZipCodeValidator implements StringValidator {
    isAcceptable(s: string) {
        return s.length === 5 && numberRegexp.test(s);
    }
}
export { ZipCodeValidator };
export { ZipCodeValidator as mainValidator };
```
���Ǿ�����ȥ��չ����ģ�飬����ֻ�����Ǹ�ģ��Ĳ������ݡ� ���µ������ܲ������ڵ�ǰģ�鵼���Ǹ�ģ�����һ���µľֲ�������
```ts
export class ParseIntBasedZipCodeValidator {
    isAcceptable(s: string) {
        return s.length === 5 && parseInt(s).toString() === s;
    }
}

// ����ԭ�ȵ���֤��������������
export {ZipCodeValidator as RegExpBasedZipCodeValidator} from "./ZipCodeValidator";
```
����һ��ģ����԰������ģ�飬�������ǵ���������������һ��ͨ���﷨��export * from "module"��

### ����
ģ��ĵ�������뵼��һ���򵥡� ����ʹ������ import��ʽ֮һ����������ģ���еĵ������ݡ�

> ����һ��ģ���е�ĳ����������
```ts
import { ZipCodeValidator } from "./ZipCodeValidator";
let myValidator = new ZipCodeValidator();

// ���ԶԵ�������������
import { ZipCodeValidator as ZCV } from "./ZipCodeValidator";
let myValidator = new ZCV();

// ������ģ�鵼�뵽һ����������ͨ����������ģ��ĵ�������
import * as validator from "./ZipCodeValidator";
let myValidator = new validator.ZipCodeValidator();

//��ͺ�����������ֱ�ӱ����ΪĬ�ϵ����� ���ΪĬ�ϵ�������ͺ����������ǿ���ʡ�Ե�
/**ZipCodeValidator.ts*/
export default class ZipCodeValidator {
    static numberRegexp = /^[0-9]+$/;
    isAcceptable(s: string) {
        return s.length === 5 && ZipCodeValidator.numberRegexp.test(s);
    }
}
import validator from "./ZipCodeValidator";

let myValidator = new validator();
// ����
/**StaticZipCodeValidator.ts*/
const numberRegexp = /^[0-9]+$/;

export default function (s: string) {
    return s.length === 5 && numberRegexp.test(s);
}

import validate from "./StaticZipCodeValidator";

let strings = ["Hello", "98052", "101"];

// Use function validate
strings.forEach(s => {
  console.log(`"${s}" ${validate(s) ? " matches" : " does not match"}`);
});


```

##### export = �� import = require()
CommonJS��AMD�Ļ����ﶼ��һ��exports�������������������һ��ģ������е������ݡ�

CommonJS��AMD��exports�����Ա���ֵΪһ������, ��������������þ������� es6 �﷨���Ĭ�ϵ������� export default�﷨�ˡ���Ȼ�������ƣ����� export default �﷨�����ܼ���CommonJS��AMD��exports��

Ϊ��֧��CommonJS��AMD��exports, TypeScript�ṩ��export =�﷨��

export =�﷨����һ��ģ��ĵ������� ����Ķ���һ��ָ�����࣬�ӿڣ������ռ䣬������ö�١�

��ʹ��export =����һ��ģ�飬�����ʹ��TypeScript���ض��﷨import module = require("module")�������ģ�顣


##### ����ģ�����
���ݱ���ʱָ����ģ��Ŀ���������������������Ӧ�Ĺ�Node.js (CommonJS)��Require.js (AMD)��UMD��SystemJS��ECMAScript 2015 native modules (ES6)ģ�����ϵͳʹ�õĴ��롣 ��Ҫ�˽����ɴ����� define��require �� register�����壬��ο���Ӧģ����������ĵ���

���������˵���˵��뵼�������ʹ�õ���������ôת��Ϊ��Ӧ��ģ�����������ġ�

##### ʹ��������JavaScript��
Ҫ��������TypeScript��д���������ͣ�������Ҫ�����������¶����API��

���ǽ���������Ϊ�����ǡ��ⲿ���򡱵ľ���ʵ�֡� ����ͨ������ .d.ts�ļ��ﶨ��ġ� �������ϤC/C++������԰����ǵ��� .h�ļ��� �����ǿ�һЩ���ӡ�

�ⲿģ��
��Node.js��󲿷ֹ�����ͨ������һ������ģ��ʵ�ֵġ� ���ǿ���ʹ�ö����� export������Ϊÿ��ģ�鶼����һ��.d.ts�ļ�������û���д��һ�����.d.ts�ļ�� ����ʹ���빹��һ���ⲿ�����ռ����Ƶķ�������������ʹ�� module�ؼ��ֲ��Ұ�����������������������֮��import�� ���磺

```ts
declare module "url" {
    export interface Url {
        protocol?: string;
        hostname?: string;
        pathname?: string;
    }

    export function parse(urlStr: string, parseQueryString?, slashesDenoteHost?): Url;
}

declare module "path" {
    export function normalize(p: string): string;
    export function join(...paths: any[]): string;
    export let sep: string;
}
```



