package main

import (
	"encoding/json"
	"fmt"
	"io"
)

// Products products
type Products struct {
	Products []*Product
}

// Product product
type Product struct {
	Name     string
	Price    float64
	Quantity int
}

func (p *Product) disp() {
	fmt.Printf("Name: %s\n", p.Name)
	fmt.Printf("Price: $%.2f\n", p.Price)
	fmt.Printf("Quantity on hand: %d\n", p.Quantity)
}

func parse(r io.Reader) (*Products, error) {
	var products Products
	err := json.NewDecoder(r).Decode(&products)
	return &products, err
}
