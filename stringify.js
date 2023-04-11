const str = process.argv[2];

console.log(
  str
    .replaceAll(" ", "_")
    .replaceAll(".", "_")
    .split("_")
    .filter((st) => st.length > 0)
    .join("_")
);
