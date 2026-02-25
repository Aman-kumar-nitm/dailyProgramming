
// focus thing 
// let finalans=[] we are able to push anything inside this
// let count1=new Array(26).fill(0)
// let ans=[arr[i]]
// call using this.findans()
// char conversion ch.charCodeAt(i)-97
class Solution {

    findans(arr, vis, ans, index) {
        let count1 = new Array(26).fill(0);

        for (let ch of arr[index]) {
            count1[ch.charCodeAt(0) - 97]++;
        }

        for (let j = index + 1; j < arr.length; j++) {
            let count2 = new Array(26).fill(0);

            for (let ch of arr[j]) {
                count2[ch.charCodeAt(0) - 97]++;
            }

            // match
            let isit = true;
            for (let i = 0; i < 26; i++) {
                if (count1[i] !== count2[i]) {
                    isit = false;
                    break;
                }
            }

            if (isit) {
                ans.push(arr[j]);
                vis[j] = 1;
            }
        }
    }

    anagrams(arr) {
        let finalans = [];
        let vis = new Array(arr.length).fill(0);

        for (let i = 0; i < arr.length; i++) {
            if (vis[i] === 0) {
                vis[i] = 1;
                let ans = [arr[i]];
                this.findans(arr, vis, ans, i);
                finalans.push(ans);
            }
        }

        finalans.sort();
        return finalans;
    }
}