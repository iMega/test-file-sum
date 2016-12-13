default:
	docker run --rm -v $(CURDIR):/data -w /data alpine ./run_test.sh
