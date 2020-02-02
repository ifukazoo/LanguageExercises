use std::io::Write;

fn main() -> std::io::Result<()> {
    let mut employees = vec![
        "Jhon Smith",
        "Jackie Jackson",
        "Chris Jones",
        "Amanda Cullen",
        "Jeremy Goodwin",
    ];
    disp_employees(&employees);
    println!("");
    print!("Enter an employee name to remove: ");
    std::io::stdout().flush()?;

    let mut employee = String::new();
    std::io::stdin().read_line(&mut employee)?;
    let employee = employee.trim();
    println!("");

    let mut found = false;
    for i in 0..employees.len() {
        if employees[i] == employee {
            employees.remove(i);
            found = true;
            break;
        }
    }

    if found {
        disp_employees(&employees);
    } else {
        println!("Not found {}.", employee);
    }

    Ok(())
}

fn disp_employees(employees: &Vec<&str>) {
    println!("There are {} employees:", employees.len());

    for i in employees {
        println!("{}", i);
    }
}
