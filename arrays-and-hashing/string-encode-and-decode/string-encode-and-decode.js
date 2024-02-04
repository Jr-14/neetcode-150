/**
String Encode and Decode

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]

Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]

Constraints:

    0 <= strs.length < 100
    0 <= strs[i].length < 200
    strs[i] contains only UTF-8 characters.

*/

/**
 * Check if a character is an integer type.
 * 
 * @param {string} char - A character
 * @returns {boolean} - True if it is a numeric type, false otherwise.
 */
function isInteger(char) {
    if (typeof char != 'string') return false;
    return !isNaN(char) && !isNaN(parseInt(char));
}

/**
 * Encode a list of strings to a single string.
 * 
 * @param {string[]} strs - A list of string to encode
 * @returns {string} An encoded string
 */
function encode(strs) {
    return strs
        .map((s) => `${s.length}#${s}`)
        .reduce((concatenatedString, s) => `${concatenatedString}${s}`, '')
}

/**
 * Decode a string to a list of strings.
 * 
 * @param {string} str - A string to decode
 * @returns {string[]} A list of string
 */
function decode(str) {
    const output = [];
    let stringLengthToRead = '';
    for (let i = 0; i < str.length; i++) {
        console.log(i);
        const currentChar = str[i];
        const prevChar = str[i - 1];
        if (isInteger(currentChar)) {
            stringLengthToRead = `${stringLengthToRead}${currentChar}`;
        } else if (isInteger(prevChar) && currentChar === '#') {
            const readString = str.slice(i + 1, i + 1 + parseInt(stringLengthToRead));
            console.log(readString);
            output.push(readString);
            i += parseInt(stringLengthToRead);
            stringLengthToRead = 0;
        }
    }
    return output;
}

function main() {
    const input = ["neet","code","love","you"];
    const output = encode(input);
    console.log(output);
    const inputBack = decode(output);
    console.log(inputBack);

    console.log(isInteger('a'));
}

main();
