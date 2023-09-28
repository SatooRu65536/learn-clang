use std::io;

fn std_input_int() -> u32 {
    let mut buffer = String::new();
    match io::stdin().read_line(&mut buffer) {
        Ok(_) => buffer.trim().parse().expect("Failed to parse."),
        Err(e) => panic!("Failed to read line: {}", e),
    }
}

fn main() {
    let loop_num: u32;

    print!("min: ");
    loop_num = std_input_int();
    println!("");

    for _n in 1..loop_num {
        println!("Hello, world!");
    }
}
