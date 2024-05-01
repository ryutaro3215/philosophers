num_execution=$1;
output_file=$2;

if [ -f "$output_file" ]; then
	rm "$output_file"
fi

for ((i=0; i<num_execution; i++))
do
	./test >> "$output_file"
done

echo "Done!"
