PROGRAM		:= currentTime
FUNCIONZIP	:= function.zip

all:   $(FUNCIONZIP)
	aws lambda update-function-code --function-name currentTime --zip-file fileb://function.zip --region ap-northeast-1

$(PROGRAM): main.go
	GOOS=linux go build -o $(PROGRAM) main.go

$(FUNCIONZIP): $(PROGRAM)
	zip $(FUNCIONZIP) $(PROGRAM)

.PHONY:clean
clean:
	rm -rf $(PROGRAM) $(FUNCIONZIP)

