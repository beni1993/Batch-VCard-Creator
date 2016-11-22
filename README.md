# Batch VCard Creator

A small tool, that creates a VCard with multiple entries, from a text file.

## Motivation

In the past, I needed a tool that creates a VCard with multiple entries. I wasn't able to find a simple and suitable tool. That is why I programmed this tool.

## Install

* Ubuntu

Download or clone this project. Unzip the project into an empty folder. Open the folder in the terminal. Run the following commands:

```sh
make
make clear
```

If you build this tool successfull, you can use it via commandline.

```sh
./bvcard-creator sourcelist.txt -o vcard.vcf
```

If you want to use it anywhere, copy `bvcard-creator` to a directory, like `/usr/bin/`.

## How to use

* Create a source text file with your data using this format:

```sh
firstname secondname mobilephonenumber
```

For example:

```sh
Max Mustermann 1234567
Erika Mustermann 7654321
John Doe 2468135
```

* Open the Terminal, and write:

```sh
bvcard-creator sourcelist.txt -o vcard.vcf
```

* Get your Vcard.

## License

This project is licensed under the zlib/libpng License. Read the [LICENSE](LICENSE) for more details.
