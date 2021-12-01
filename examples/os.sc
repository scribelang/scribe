let io = @import("std/io");
let os = @import("std/os");
let string = @import("std/string");

let main = fn(): i32 {
	let p = os.getEnv("PATH");
	io.println("PATH is: ", p);
	let newpath = string.from(p);
	defer newpath.deinit();
	newpath.appendCStr(":/tmp/bin");
	os.setEnv("PATH", newpath.cStr(), true);
	io.println("Final PATH is: ", os.getEnv("PATH"));
	return 0;
};