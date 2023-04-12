/**
 * @link : https://leetcode.com/problems/simplify-path/description/
 * @time_taken : 00:07:00
 *
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function (path) {
  /**
      "/" : points to some directory, not needed to push in stack
              as we will join the stack with '/' eventually
      "." : ponts to current directory, not needed, should be filtered
      ".." : we are going up in the directory level, stack pop op
      "any-other-string" : should be pushed in stack
  */

  const ignoreParts = ["/", ".", ""];
  const parts = path.split("/").filter((p) => !ignoreParts.includes(p));

  const stack = [];
  for (let p of parts) {
    if (ignoreParts.includes(p)) continue;
    else if (p === "..") stack.pop();
    else stack.push(p);
  }

  return "/" + stack.join("/");
};
