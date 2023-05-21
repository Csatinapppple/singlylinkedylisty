use std::io;

struct Node{
    data: u32,
    next: Option<Box<Node>>,
}

fn main(){
    let choice: u8 = 0;

    let _head_node: Option<Node>=None;

    while choice != 4 {
        let mut buffer = String::new();
        io::stdin().read_line(&mut buffer);

        print_choices();
    }
}

fn print_choices(){
    println!("1. ADD NODE");
    println!("2. REMOVE NODE");
    println!("3. PRINT NODES");
    println!("4. EXIT");
}
