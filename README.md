# Batch VCard Creator

A little Tool, which create, from a text file, a VCard with multiple entries.

## Motivation

In the past, I need a Tool which create a VCard with multiple entries. I could not find a simple and suitable Tool for me. That is why I wrote this tool.

## Install

* Ubuntu

Download or clone this project. Unzip the project in a empty folder. Change in this folder. Run the following commands:

```sh
make
make clear
```

If you build this Tool successfull, you can use it via commandline.

```sh
./bvcard-creator sourcelist.txt -o vcard.vcf
```

If you want to use it everywhere, copy `bvcard-creator` to a dir like `/usr/bin/`.

## How to use

* Create a source text file with your data, in this format:

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

This project is licensed under the zlib/libpng License. Read the [LICENSE](LICENSE) file for more details.
