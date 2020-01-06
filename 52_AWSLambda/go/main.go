package main

import (
	"context"
	"encoding/json"
	"time"

	"github.com/aws/aws-lambda-go/lambda"
)

type Mybody struct {
	CurrentTime string `json:"currentTime"`
}
type Headers struct {
}

type MyResponse struct {
	StatusCode      string  `json:"statusCode"`
	headers         Headers `json:"headers"`
	Body            string  `json:"body"`
	IsBase64Encoded bool    `json:"isBase64Encoded"`
}

func HandleRequest(ctx context.Context) (*MyResponse, error) {
	bytes, err := json.Marshal(Mybody{time.Now().Format("2006-01-02 15:04:05")})
	if err != nil {
		return nil, err
	}
	return &MyResponse{"200", Headers{}, string(bytes), false}, nil
}

func main() {
	lambda.Start(HandleRequest)
}
