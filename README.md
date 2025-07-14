TEST

echo -e "hello\nworld" > infile
./pipex infile "ls -l" "wc -l" outfile

bonus
echo -e "hello\nworld\nfoo\nbar" > infile
./pipex_bonus infile "grep o" "sort" "wc -l" outfile
< infile grep o | sort | wc -l > outfile
